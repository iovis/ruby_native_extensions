use magnus::{function, prelude::*, Error, Ruby};

use self::range_ext::FullOverlapExt;
use rayon::prelude::*;

mod parse;
mod range_ext;

fn run(input: String) -> usize {
    input
        .par_lines()
        .map(parse::line)
        .filter(|(a, b)| a.full_overlap(&b))
        .count()
}

#[magnus::init]
fn init(ruby: &Ruby) -> Result<(), Error> {
    let module = ruby.define_module("RsDay4")?;
    module.define_singleton_method("rs_run", function!(run, 1))?;
    Ok(())
}
