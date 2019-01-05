/* 
- mapi over string1
-  get ith position of string 2
- if equal, add to output string
*/

let findCommonLetterPositions = (str1: string, str2: string) => {
    let output = ref("");
    String.iteri((idx, letter) => {
        switch(String.get(str2, idx) == letter) {
            | false => ();
            | true => {
                output := output^ ++ String.make(1, letter)
            }
        }
    }, str1)
    output^
}
