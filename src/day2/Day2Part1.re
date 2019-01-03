/* 
- Iterate over list
- Analyse each entry for duplicate characters
- Analyse each entry for triplicate characters
*/
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
            ! hasLetter(substring2)}
        }
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