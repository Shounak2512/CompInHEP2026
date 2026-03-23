#!/usr/bin/env python
# This example is NOT working!

import ROOT

ROOT.gROOT.SetBatch(True)

def main():
    x = [1,3]
    y = [1,2]

    n = len(x)

    canvas = ROOT.TCanvas("someName","",500,500)
    canvas.SetFillColor(0)
    canvas.cd()

    frame = ROOT.TH2F("frame","",2,0,4,2,0,3)
    frame.SetStats(0)
    frame.GetXaxis().SetTitle("x")
    frame.GetYaxis().SetTitle("y")
    frame.Draw()

    graph = ROOT.TGraph(n,x,y)
    graph.SetMarkerStyle(2)
    graph.SetMarkerColor(2)
    graph.Draw("PL")

    canvas.Print("graph.eps")

if __name__ == "__main__":
    main()
