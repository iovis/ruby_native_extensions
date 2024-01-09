use std::ops::RangeInclusive;

pub trait FullOverlapExt {
    fn full_overlap(&self, other: &Self) -> bool;
}

impl<T: PartialOrd> FullOverlapExt for RangeInclusive<T> {
    fn full_overlap(&self, other: &Self) -> bool {
        (self.start() <= other.start() && self.end() >= other.end())
            || (other.start() <= self.start() && other.end() >= self.end())
    }
}
