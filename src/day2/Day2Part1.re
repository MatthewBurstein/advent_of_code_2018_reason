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

let isDuplicate = (str: string, testLetter: char) => {
    let firstOccurenceIdx = String.index(str, testLetter);
    switch (String.contains_from(str, firstOccurenceIdx + 1, testLetter)) {
    | false => false;
    | true => {
            let secondOcurrenceIdx = String.index_from(str, firstOccurenceIdx + 1, testLetter);
            ! String.contains_from(str, secondOcurrenceIdx + 1, testLetter);
        };
    };
};