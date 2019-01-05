open Jest;
open Expect;
open Day2Part2;

describe("findCommonLetterPositions", () => {
    test("returns string for identical strings", () => {
        expect(findCommonLetterPositions("abc", "abc")) |> toEqual("abc")
    })

    test("returns matching letter positions for two different strings", () => {
        expect(findCommonLetterPositions("abc", "amc")) |> toEqual("ac")
    })
})