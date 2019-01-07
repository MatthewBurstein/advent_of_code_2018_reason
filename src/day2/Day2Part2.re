type match = NoMatch | CommonCharacters(string);

let compareLength = (stringForBase: string, stringUnderTest: string) => {
    String.length(stringUnderTest) == String.length(stringForBase) - 1;
}

let areCorrectBoxes = (id1: string, id2: string): match => {
    let output = ref("");
    String.iteri((idx, id1Letter) => {
        switch(String.get(id2, idx)) {
            | id2Letter when id2Letter != id1Letter => ();
            | id2Letter => {
                output := output^ ++ String.make(1, id2Letter);
            };
        };
    }, id1);
    compareLength(id1, output^) ? CommonCharacters(output^) : NoMatch;
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
        | NoMatch => analyseSingleId(id, rest);
        | CommonCharacters(chars) => CommonCharacters(chars);
        | exception Invalid_argument("index out of bounds") => NoMatch;
    };
};

let rec findCorrectBoxes = (data: list(string)): string => {
    let (testElement, rest) = extractFirstElement(data);
    switch(analyseSingleId(testElement, rest)) {
        | NoMatch => findCorrectBoxes(rest);
        | CommonCharacters(chars) => chars;
    };
};