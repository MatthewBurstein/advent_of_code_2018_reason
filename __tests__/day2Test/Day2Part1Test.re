open Jest;
open Expect;
open Day2Part1;

describe("buildSubstringAfterOccurence", () => {
    test("if character is present returns substring of string starting after first occurence", () => {
        let testString = "abcdefg";
        expect(getSubstringAfterOccurence('c', testString)) |> toEqual("defg");
    });
})

describe("isDuplicate", () => {
    test("returns false when string contains character once", () => {
        let noDuplicates = "abcdefg";
        expect(isDuplicate(noDuplicates, 'c')) |> toEqual(false);
    })

    test("returns true when string contains character exactly twice", () => {
        let oneDuplicate = "anshdbar";
        expect(isDuplicate(oneDuplicate, 'a')) |> toEqual(true);
    });

    test("returns false when string contains character three times", () => {
        let oneTriplicate = "anhgabsal";
        expect(isDuplicate(oneTriplicate, 'a')) |> toEqual(false);
    })
});

describe("isTriplicate", () => {
    test("returns false when letter appears only once", () => {
        let noTriplicate = "abcdef";
        expect(isTriplicate(noTriplicate, 'a')) |> toEqual(false);
    });

    test("returns false when letter appears twice", () => {
        let oneDuplicate = "anshdbar";
        expect(isTriplicate(oneDuplicate, 'a')) |> toEqual(false);
    })    
    
    test("returns true when letter appears three times", () => {
        let oneTriplicate = "anshadbar";
        expect(isTriplicate(oneTriplicate, 'a')) |> toEqual(true);
    })

    test("returns false when letter appears four times", () => {
        let oneQuadruplicate = "ansahadbar";
        expect(isTriplicate(oneQuadruplicate, 'a')) |> toEqual(false);
    })
});