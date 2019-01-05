open Jest;
open Expect;
open Day2Part2;

describe("findCommonLetterPositions", () => {
    test("returns string for identical strings", () => {
        expect(findCommonLetterPositions("abc", "abc")) |> toEqual("abc");
    });

    test("returns matching letter positions for two different strings", () => {
        expect(findCommonLetterPositions("abc", "amc")) |> toEqual("ac");
    });
})

describe("areCorrectBoxes", () => {
    test("returns (true, commonLetterPositions) if ids differ in exactly one place", () => {
        expect(areCorrectBoxes("abcde", "abcze")) |> toEqual("abce");
    });

    test("returns (false, emptyString) if ids differ in no places", () => {
        expect(areCorrectBoxes("abcde", "abcde")) |> toEqual( "");
    });

    test("returns (false, emptyString) if ids differ in more than one place", () => {
        expect(areCorrectBoxes("abcde", "azxye")) |> toEqual("");
    });
});

describe("analyseSingleId", () => {
    test("returns empty string if there is no off by one id match in the list", () => {
        let id = "abcde"
        let testData = ["defgh", "ghijk", "lkjhg"];
        expect(analyseSingleId(id, testData)) |> toEqual("")
    });

    test("returns matched characters if there is an off by one id match in the list", () => {
        let id = "match";
        let testData = ["defgh", "ghijk", "mztch", "lkjhg"];
        expect(analyseSingleId(id, testData)) |> toEqual("mtch")
    });
});

describe("findCorrectBoxes", () => {
    test("returns the common letter positions of the two ids which differ in exactly one place", () => {
        let testData = ["abcde", "samez", "nhjki", "samex", "edghi"];
        expect(findCorrectBoxes(testData)) |> toEqual("same");
    });
});