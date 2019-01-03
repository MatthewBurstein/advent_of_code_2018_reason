open Jest;
open Expect;
open Day2Part1;

describe("countOccurences", () => {
    test("returns 2 when character appears twice", () => {
        expect(countOccurences("abcb", 'b')) |> toEqual(2);
    });
});
