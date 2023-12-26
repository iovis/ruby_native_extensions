use magnus::{function, prelude::*, Error, Ruby};

use self::range_ext::FullOverlapExt;
use rayon::prelude::*;

mod parse;
mod range_ext;

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

fn try_run(ruby: &Ruby, input: String) -> Result<usize, Error> {
    let mut count = 0;

    for line in input.lines() {
        let (_, (a, b)) = parse::try_line(line)
            .map_err(|err| Error::new(ruby.exception_arg_error(), err.to_string()))?;

        if a.full_overlap(&b) {
            count += 1;
        }
    }

    Ok(count)
}

#[magnus::init]
fn init(ruby: &Ruby) -> Result<(), Error> {
    let module = ruby.define_module("RsDay4")?;
    module.define_singleton_method("run", function!(run, 1))?;
    module.define_singleton_method("run_parallel", function!(run_parallel, 1))?;
    module.define_singleton_method("try_run", function!(try_run, 1))?;
    Ok(())
}
