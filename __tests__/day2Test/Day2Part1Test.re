open Jest;
open Expect;
open Day2Part1;

describe("countOccurences", () => {
    test("returns 2 when character appears twice", () => {
        expect(countOccurences("abcb", 'b')) |> toEqual(2);
    });

    test("returns 3 when character appears 3 times", () => {
        expect(countOccurences("abcbaca", 'a')) |> toEqual(3);
    });
});
