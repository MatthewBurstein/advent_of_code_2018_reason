open Jest; 
open Expect;
open Day3Part1;
open Day3DataInterpreter;

 let fourByFive = {
            id: 1,
            colStart: 3,
            rowStart: 4,
            height: 4,
            width: 5
        };

describe("getColumnNumbers", () => {
    test("builds a list column numbers", () => {       
        expect(getColumnNumbers(fourByFive)) |> toEqual([3, 4, 5, 6, 7]);
    });
});

describe("getFirstRowPoints", () => {
    test("builds first row of points", () => {
        let expected = [(3, 4), (4, 4), (5, 4), (6, 4), (7, 4)]
        expect(getFirstRowPoints(fourByFive)) |> toEqual(expected);
    })
})

describe("buildColumnPointsFromTop", () => {
    test("builds a column of points given a rectangle and the top point", () => {
        let firstPoint = (4, 5)
        let expectedColumn = [(4, 5), (4, 6), (4, 7), (4, 8)]
        expect(buildColumnPointsFromTop(fourByFive, firstPoint)) |> toEqual(expectedColumn)
    })
})

describe("buildPointsList", () => {
    test("returns correct list of points for 1x1 rectangle", () => {
        let oneByOne = {
            id: 1,
            colStart: 2,
            rowStart: 2, 
            height: 1,
            width: 1
        };
        expect(buildPointsList(oneByOne)) |> toEqual([(2,2)]);
    });

    test("returns correct list of points for 2 x 3 rectangle", () => {
        let twoByThree = {
            id: 1,
            colStart: 3,
            rowStart: 4, 
            height: 2,
            width: 3
        };
        let expectedPoints = [(3, 4), (3, 5),
                              (4, 4), (4, 5),
                              (5, 4), (5, 5)];

        expect(buildPointsList(twoByThree)) |> toEqual(expectedPoints);
    });
});