/* 
- Iterate over list
- Analyse each entry for duplicate characters
- Analyse each entry for triplicate characters
*/

let increaseCountIfEqual = (count: int, first: char, second: char) => {
    first == second ? count + 1 : count;
}

let countOccurences = (str: string, letter: char) => {
    let count = ref(0);
    String.iter(
        (strElement) => {count := increaseCountIfEqual(count^, strElement, letter)},
        str)
    count^;
}

let getSubstringAfterOccurence = (str: string, letter: char) => {
    let idxAfterOccurence = String.index(str, letter) + 1;
    String.sub(str, idxAfterOccurence, String.length(str) - idxAfterOccurence);
};

let isDuplicate = (str: string, letter: char) => {
    switch (String.contains(str, letter)) {
    | false => false;
    | true => {
        let substring1 = getSubstringAfterOccurence(str, letter);
        switch (String.contains(substring1, letter)) {
        | false => false;
        | true => {
            let substring2 = getSubstringAfterOccurence(substring1, letter);
            ! String.contains(substring2, letter)}
        }
    };
    };
};