let findCommonLetterPositions = (id1: string, id2: string) => {
    let output = ref("");
    String.iteri((idx, letter) => {
        switch(String.get(id2, idx) == letter) {
            | false => ();
            | true => {
                output := output^ ++ String.make(1, letter);
            };
        };
    }, id1);
    output^;
};

let areCorrectBoxes = (id1: string, id2: string) => {
    let commonPositions = findCommonLetterPositions(id1, id2);
    String.length(id1) == String.length(commonPositions) + 1 ? commonPositions : "";
};

let extractFirstElement = (theList: list('a)) => {
    switch(theList) {
        | [] => ("", []);
        | [element,...tail] => (element, tail);
    };
};

let rec analyseSingleId = (id: string, data: list(string)) => {
    let (testElement, rest) = extractFirstElement(data);
    switch(areCorrectBoxes(id, testElement)) {
        | "" => analyseSingleId(id, rest);
        | commonCharacters => commonCharacters;
        | exception Invalid_argument("index out of bounds") => "";
    };
};

let rec findCorrectBoxes = (data: list(string)): string => {
    let (testElement, rest) = extractFirstElement(data);
    switch(analyseSingleId(testElement, rest)) {
        | "" => findCorrectBoxes(rest);
        | commonCharacters => commonCharacters;
    };
};