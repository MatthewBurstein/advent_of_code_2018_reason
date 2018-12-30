open Jest;
open Expect;
open Day1Part2;

describe("updateTotals", () => {
    test("creates new array when array is empty", () => {
        expect(updateTotals(1, [||])) |> toEqual([|1|]);
    });

    test("appends element to array when array is not empty", () => {
        expect(updateTotals(2, [|3,46,4,5|])) |> toEqual([|2,3,46,4,5|])
    });
});

describe("incrementIndex", () => {
    test("increases index by one when index less than array length", () => {
        expect(incrementIndex([|1,2,3,4,5|], 1)) |> toEqual(2)
    })

    test("returns 0 when index == arr.length - 1", () => {
        expect(incrementIndex([|1,2,3,4|], 3)) |> toEqual(0);
    });
});

describe("getNextTotal", () => {
    test("returns value when array empty", () => {
        expect(getNextTotal(3, [||])) |> toEqual(3);
    });

    test("returns sum of value and head of array when array not empty", () => {
        expect(getNextTotal(4, [|23, 45, 63|])) |> toEqual(27);
    });
});

describe("isRepeat", () => {
    test("returns false for empty array", () => {
        expect(isRepeat(1, [||])) |> toEqual(false);
    });

    test("returns false for single element array not matching argument", () => {
        expect(isRepeat(1, [|2|])) |> toEqual(false)
    });

    test("returns true for single element array matching argument", () => {
        expect(isRepeat(1, [|1|])) |> toEqual(true)
    });

    test("returns false for many element array with no match", () => {
        expect(isRepeat(1, [|2,3,4|])) |> toEqual(false)
    });

    test("returns true for many element with a match", () => {
        expect(isRepeat(3, [|1,4,3|])) |> toEqual(true);
    });
});

describe("processDatum", () => {()
  test("evaluates a single iteration", () => {
    let data = [|1,2,3|];
    let totals = [|4,5,6|];
    expect(processDatum((data, 1, totals, false))) |> toEqual((data, 2, [|6,4,5,6|], true))
  });
});

describe("result", () => {
    test("processes a simple version of the problem", () => {
        let data = [|1,1,-1|];
        let init = (data, 0, [||], false);
        expect(result(init)) |> toEqual((data, 0, [|1, 2, 1|], true))
    });
})