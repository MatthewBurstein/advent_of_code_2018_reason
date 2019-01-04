let getSubstringAfterOccurence = (letter: char, str: string) => {
    let idxAfterOccurence = String.index(str, letter) + 1;
    String.sub(str, idxAfterOccurence, String.length(str) - idxAfterOccurence);
};

let stringContainsChar = (letter: char, str: string) => {
    String.contains(str, letter)
}

let isDuplicate = (str: string, letter: char) => {
    let hasLetter = stringContainsChar(letter);
    let getSubstring = getSubstringAfterOccurence(letter);
    switch (hasLetter(str)) {
    | false => false;
    | true => {
        let substring1 = getSubstring(str);
        switch (hasLetter(substring1)) {
            | false => false;
            | true => {
                let substring2 = getSubstring(substring1);
                ! hasLetter(substring2)
                };
            };
        };
    };
};

let isTriplicate = (str: string, letter: char) => {
    let hasLetter = stringContainsChar(letter);
    let getSubstring = getSubstringAfterOccurence(letter);
    switch (hasLetter(str)) {
        | false => false;
        | true => {
            let substring1 = getSubstring(str);
            switch (hasLetter(substring1)) {
                | false => false;
                | true => {
                    let substring2 = getSubstring(substring1);
                    switch (hasLetter(substring2)) {
                        | false => false;
                        | true => {
                            let substring3 = getSubstring(substring2);
                            ! hasLetter(substring3);                   
                        };
                    };
                };
            };
        };
    };
};

let hasDuplicate = (str: string) => {
    let break = ref(false);
    let duplicatePresent = ref(false);
    let position = ref(0);
    while(! break^) {
        let testLetter = String.get(str, position^);
        switch (isDuplicate(str, testLetter)) {
            | false => position := position^ + 1;
            | true => {
                break := true;
                duplicatePresent := true;
            }
        }
        if (position^ == String.length(str) - 1) {
            break := true
        }
    };
    duplicatePresent^;
}

let hasTriplicate = (str: string) => {
    let break = ref(false);
    let triplicatePresent = ref(false);
    let position = ref(0);
    while(! break^) {
        let testLetter = String.get(str, position^);
        switch (isTriplicate(str, testLetter)) {
            | false => position := position^ + 1;
            | true => {
                break := true;
                triplicatePresent := true;
            }
        }
        if (position^ == String.length(str) - 1) {
            break := true
        }
    };
    triplicatePresent^;
}

let calculateChecksum = (data: list(string)) => {
    let duplicatesCount = List.filter(str => hasDuplicate(str), data)
        |> List.length;
    List.filter(str => hasTriplicate(str), data)
        |> List.length
        |> (*)(duplicatesCount);
}

let data = Day2Data.data;

print_int(calculateChecksum(data))