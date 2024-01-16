use magnus::scan_args::scan_args;
use magnus::{function, prelude::*, Ruby, Value};

type RbResult<T> = Result<T, magnus::Error>;

fn hello(args: &[Value]) -> RbResult<String> {
    let args = scan_args::<(), (Option<String>,), (), (), (), ()>(args)?;
    let (name,): (Option<String>,) = args.optional;
    let name = name.unwrap_or_else(|| String::from("World"));

    Ok(format!("Hello, {name}"))
}

fn excited_hello(args: &[Value]) -> RbResult<String> {
    Ok(format!("{}!", hello(args)?.to_uppercase()))
}

fn fib(n: u64) -> u64 {
    match n {
        0 | 1 => n,
        _ => fib(n - 1) + fib(n - 2),
    }
}

#[magnus::init]
fn init(ruby: &Ruby) -> RbResult<()> {
    let module = ruby.define_module("RsHello")?;
    module.define_singleton_method("hello", function!(hello, -1))?;
    module.define_singleton_method("hello!", function!(excited_hello, -1))?;
    module.define_singleton_method("fib", function!(fib, 1))?;
    Ok(())
}
