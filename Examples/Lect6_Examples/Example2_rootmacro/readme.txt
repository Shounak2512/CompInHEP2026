Execute the ROOT script by typing
root plot.cxx
Exit with .q

Next open root command prompt by typing root

.L plot.cxx+ wont work, you need to include the used class headers

They are included in plot_v2.cxx:
.L plot_v2.cxx+ 
plot_v2()
