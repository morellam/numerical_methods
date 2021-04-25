# numerical_methods
Repository with exercises done for HE-8 numerical methods course at GSSI XXXVI cycle. 

To compile, run the code and plot the results for a specific algorithm just execute:
<pre>
make <i>algorithm_name</i>
</pre>

Available *algorithm_name* :
- simpson
- rungekutta

Executables files are saved in the *output* directory generated by `make` while `.txt` files are saved in *pyplot*.

If you want to remove executables and text files generated at runtime:
```
make clean
```
