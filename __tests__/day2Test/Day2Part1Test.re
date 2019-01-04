open Jest;
open Expect;
open Day2Part1;

describe("buildSubstringAfterOccurence", () => {
    test("if character is present returns substring of string starting after first occurence", () => {
        let testString = "abcdefg";
        expect(getSubstringAfterOccurence('c', testString)) |> toEqual("defg");
    });
});

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

describe("hasDuplicate", () => {
    test("returns true when a duplicate is present", () => {
        let oneDuplicate = "skjdhfd";
        expect(hasDuplicate(oneDuplicate)) |> toEqual(true);
    });

    test("returns true when has a duplicate and a triplicate", () => {
        let duplicateAndTriplicate = "abhadha";
        expect(hasDuplicate(duplicateAndTriplicate)) |> toEqual(true);
    });

    test("returns false when no duplicate is present", () => {
        let noDuplicates = "asdghjk";
        expect(hasDuplicate(noDuplicates)) |> toEqual(false);
    });

    test("returns false when has a triplicate and no duplicate", () => {
        let oneTriplicate = "asdfaghjak";
        expect(hasDuplicate(oneTriplicate)) |> toEqual(false);
    })
});


describe("hasTriplicate", () => {
    test("returns true when a triplicate is present", () => {
        let oneTriplicate = "sdkjdhfd";
        expect(hasTriplicate(oneTriplicate)) |> toEqual(true);
    });

    test("returns true when has a duplicate and a triplicate", () => {
        let duplicateAndTriplicate = "abhadha";
        expect(hasTriplicate(duplicateAndTriplicate)) |> toEqual(true);
    });

    test("returns false when no triplicate is present", () => {
        let noDuplicates = "asdghjk";
        expect(hasTriplicate(noDuplicates)) |> toEqual(false);
    });

    test("returns false when has a duplicate and no triplicate", () => {
        let oneTriplicate = "sdfaghjak";
        expect(hasTriplicate(oneTriplicate)) |> toEqual(false);
    })
});

describe("calculateChecksum", () => {
    test("returns appropriate checksum for data 1", () => {
        let data = ["abc", "aab", "aaa"];
        expect(calculateChecksum(data)) |> toEqual(1);
    })

    test("returns appropriate checksum for data 2", () => {
        let data = ["bbb", "aab", "aaa"];
        expect(calculateChecksum(data)) |> toEqual(2);
    })

    test("returns appropriate checksum for data 3", () => {
        let data = ["abc", "aab", "aaa", "ccd", "ggg", "aabbac", "qquxudu"];
        expect(calculateChecksum(data)) |> toEqual(16);
    })
})