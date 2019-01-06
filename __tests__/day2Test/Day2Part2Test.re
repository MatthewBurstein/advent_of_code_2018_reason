open Jest;
open Expect;
open Day2Part2;

describe("areCorrectBoxes", () => {
    test("returns CommonCharacters(string) if ids differ in exactly one place", () => {
        expect(areCorrectBoxes("abcde", "abcze")) |> toEqual(CommonCharacters("abce"));
    });

    test("returns NoMatch if ids differ in no places", () => {
        expect(areCorrectBoxes("abcde", "abcde")) |> toEqual(NoMatch);
    });

    test("returns NoMatch if ids differ in more than one place", () => {
        expect(areCorrectBoxes("abcde", "azxye")) |> toEqual(NoMatch);
    });
});

describe("analyseSingleId", () => {
    test("returns NoMatch if there is no off by one id match in the list", () => {
        let id = "abcde"
        let testData = ["defgh", "ghijk", "lkjhg"];
        expect(analyseSingleId(id, testData)) |> toEqual(NoMatch)
    });

    test("returns CommonCharacters(string) if there is an off by one id match in the list", () => {
        let id = "match";
        let testData = ["defgh", "ghijk", "mztch", "lkjhg"];
        expect(analyseSingleId(id, testData)) |> toEqual(CommonCharacters("mtch"))
    });
});

describe("findCorrectBoxes", () => {
    test("returns the common letter positions of the two ids which differ in exactly one place", () => {
        let testData = ["abcde", "samez", "nhjki", "samex", "edghi"];
        expect(findCorrectBoxes(testData)) |> toEqual("same");
    });
});