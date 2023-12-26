use std::ops::RangeInclusive;

use nom::bytes::complete::tag;
use nom::character::complete;
use nom::combinator::map;
use nom::sequence::separated_pair;
use nom::IResult;

pub fn line(input: &str) -> (RangeInclusive<i32>, RangeInclusive<i32>) {
    let (_, ranges) = separated_pair(parse_range, tag(","), parse_range)(input)
        .expect("Ranges should be parseable");

    ranges
}

fn parse_range(input: &str) -> IResult<&str, RangeInclusive<i32>> {
    map(
        separated_pair(complete::i32, tag("-"), complete::i32),
        |(a, b)| a..=b,
    )(input)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn parse_range_test() {
        let input = "2-4,6-8";

        assert_eq!(parse_range(input), Ok((",6-8", 2..=4)));
    }

    #[test]
    fn parse_line_test() {
        let input = "2-4,6-8";

        assert_eq!(line(input), (2..=4, 6..=8));
    }
}
