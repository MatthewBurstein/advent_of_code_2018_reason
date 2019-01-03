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

describe("buildSubstringAfterOccurence", () => {
    test("if character is present returns substring of string starting after first occurence", () => {
        let testString = "abcdefg";
        expect(getSubstringAfterOccurence(testString, 'c')) |> toEqual("defg");
    });
})

describe("isDuplicate", () => {
    test("returns false when string contains character once", () => {
        let noDuplicates = "abcdefg";
        expect(isDuplicate(noDuplicates, 'c')) |> toEqual(false);
    })

    test("returns true when string contains character exactly twice", () => {
        let oneDuplicate = "anshdbar"
        expect(isDuplicate(oneDuplicate, 'a')) |> toEqual(true);
    });

    test("returns false when string contains character three times", () => {
        let oneTriplicate = "anhgabsal";
        expect(isDuplicate(oneTriplicate, 'a')) |> toEqual(false);
    })
});