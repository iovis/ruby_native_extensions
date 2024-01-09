use magnus::{function, prelude::*, Error, RString, Ruby, Value};

use self::range_ext::FullOverlapExt;
use rayon::prelude::*;

mod parse;
mod range_ext;

#[magnus::init]
fn init(ruby: &Ruby) -> Result<(), Error> {
    let module = ruby.define_module("RsDay4")?;
    module.define_singleton_method("run", function!(run, 1))?;
    module.define_singleton_method("run_parallel", function!(run_parallel, 1))?;
    module.define_singleton_method("run_parallel!", function!(run_parallel_unsafe, 1))?;
    module.define_singleton_method("try_run", function!(try_run, 1))?;
    Ok(())
}

fn run(input: String) -> usize {
    input
        .lines()
        .map(parse::line)
        .filter(|(a, b)| a.full_overlap(&b))
        .count()
}

fn run_parallel(input: String) -> usize {
    input
        .par_lines()
        .map(parse::line)
        .filter(|(a, b)| a.full_overlap(&b))
        .count()
}

fn run_parallel_unsafe(input: Value) -> usize {
    let r_string = RString::from_value(input).unwrap();
    let str = unsafe { r_string.as_str().unwrap() };

    str.par_lines()
        .map(parse::line)
        .filter(|(a, b)| a.full_overlap(&b))
        .count()
}

fn try_run(ruby: &Ruby, input: Value) -> Result<usize, Error> {
    // checks value is a String, does not call #to_str
    let r_string = RString::from_value(input)
        .ok_or_else(|| Error::new(ruby.exception_type_error(), "expected string"))?;

    // error on encodings that would otherwise need converting to utf-8
    if !r_string.is_utf8_compatible_encoding() {
        return Err(Error::new(
            ruby.exception_encoding_error(),
            "string must be utf-8",
        ));
    }

    // RString::as_str is unsafe as it's possible for Ruby to invalidate the
    // str as we hold a reference to it. The easiest way to ensure the &str
    // stays valid is to avoid any other calls to Ruby for the life of the
    // reference (the rest of the unsafe block).
    let str = unsafe { r_string.as_str()? };

    let mut count = 0;

    for line in str.lines() {
        let (_, (a, b)) = parse::try_line(line)
            .map_err(|err| Error::new(ruby.exception_arg_error(), err.to_string()))?;

        if a.full_overlap(&b) {
            count += 1;
        }
    }

    Ok(count)
}
