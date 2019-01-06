open Jest;
open Expect;
open Day3DataInterpreter;

describe("getId", () => {
    test("gets 1 digit id as integer from single claimString", () => {
        let claimString = "#3 @ 951,319: 11x24";
        expect(getId(claimString)) |> toEqual(3);
    });

    test("gets 3 digit id as integer from single claimString", () => {
        let claimString = "#602 @ 951,319: 11x24";
        expect(getId(claimString)) |> toEqual(602);
    });
});

describe ("getStartCol", () => {
    test("gets the first column this claimString uses", () => {
        let claimString = "#602 @ 951,319: 11x24";
        expect(getStartCol(claimString)) |> toEqual(952);
    })
})

describe("getStartRow", () => {
    test("gets the first row this claimString uses", () => {
        let claimString = "#602 @ 951,319: 11x24";
        expect(getStartRow(claimString)) |> toEqual(320);
    })
})

describe("getHeight", () => {
    test("returns height", () => {
        let claimString = "#602 @ 951,319: 11x24";
        expect(getHeight(claimString)) |> toEqual(11);
    })
})

describe("getWidth", () => {
    test("returns width", () => {
        let claimString = "#602 @ 951,319: 11x24";
        expect(getWidth(claimString)) |> toEqual(24);
    })
})

describe("buildClaim", () => {
    test("returns a claim with the appropriate values", () => {
        let claimString = "#602 @ 951,319: 11x24";
        let expectedClaim = {
            id: 602,
            startCol: 952,
            startRow: 320,
            height: 11,
            width: 24
        }
        expect(buildClaim(claimString)) |> toEqual(expectedClaim);
    })
})