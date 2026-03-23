make
make test
test.job

To be able to browse the Event content stored in the root file,
root analysis.root

root > gSystem->Load("libEvent.so")
root > new TBrowser
