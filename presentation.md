# Ruby Native Extensions

Ruby's default interpreter, MRI, is built on top of **C**

This means we could leverage those APIs if you need the power and raw speed of **C**

- **Python** is also written in C, so you can also do this
- If you hate yourself enough, **Node** can also be extended with **C++**
- So, **technically**, this training is for everyone

---

## Do I need a native extension?

If you need to ask yourself that question, the answer is likely **"no"**

##### Reasons to do native extensions

1. You want to **embed** Ruby in your system because of reasons
1. You have a **CPU bottleneck** (not an IO one) in a very hot path
1. You want to **wrap** a native library
1. Job security
1. You've always wanted to have a **CVE** named after you

---

### Advent of Code

##### AoC 2022: day 4

> Find if there's a full overlap between the ranges in each line.

```text
2-4,6-8
2-3,4-5
5-7,7-9
2-8,3-7
6-6,4-6
2-6,4-8
```

=> `2` lines contain ranges that fully overlap:

```text
2-3,4-5    -> 2-3 is contained within 4-5
6-6,4-6    -> 6-6 is contained within 4-6
```

https://adventofcode.com/2022/day/4

---

#### References

- https://docs.ruby-lang.org/en/master/extension_rdoc.html
- http://silverhammermba.github.io/emberb/c/
- https://blog.peterzhu.ca/ruby-c-ext/
- https://github.com/ruby/ruby/blob/master/doc/extension.rdoc
- https://github.com/matsadler/magnus
- https://github.com/iovis/ruby_native_extensions
