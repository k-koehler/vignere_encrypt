# vignere_encrypt

<h1>How to use:</h1>
<p1>run the following commands in your shell/cmd:<br>
`g++ *.h *.cc  encrypt.cpp -Wall -pedantic -o v_encpt`<br>
`g++ *.h *.cc  decrypt.cpp -Wall -pedantic -o v_dcpt`
Now you should have two executables: v_encpt and v_dcpt<br>
To encrypt a file using the Vignère Cypher, simply run the command:<br>
`v_encpt <input_file>`<br>
After doing that, the file should become encyphered. For example, with password "meow":<br>
>The quick brown fox jumped over the lazy dog. 

becomes:
>flsmgmqgnvcszjctvyalqhcrqvhdqpovkhcc

To decrypt it, simply run the command:
'v_dcpt <encrypted file>'

After running, with password "wrong password":
>flsmgmqgnvcszjctvyalqhcrqvhdqpovkhc

...becomes
>Sample text: juezanbgvdgeiggchlum

...this doesn't seem right! <br>
Now try again with the right password:
>Sample text: thequickbrownfoxjump

...this seems correct, now we should overwrite the file!</p>

<h2>NOTE:</h2>

*Non-alphabetical characters are omitted (as per original design of the cypher) including spaces. 
*It's probably pretty easy to find a glitch in here, this has not been rigorously tested. 
*It should build on both Windows and Linux (tested on Ubuntu 12). However, Linux build may fail! (has not been rigorously tested)
*No makefile, (if someone wants to make one, go ahead) I coudn't be bothered to make one!
