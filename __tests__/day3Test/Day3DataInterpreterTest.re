open Jest;
open Expect;
open Day3DataInterpreter;

describe("getId", () => {
    test("gets 1 digit id as integer from single claim", () => {
        let claim = "#3 @ 951,319: 11x24";
        expect(getId(claim)) |> toEqual(3);
    });

    test("gets 3 digit id as integer from single claim", () => {
        let claim = "#602 @ 951,319: 11x24";
        expect(getId(claim)) |> toEqual(602);
    });
});