void plot(){

  TCanvas* canvas = new TCanvas("name","title",500,500);
  canvas->SetFillColor(0);

  TH2F* frame = new TH2F("frame","",2,0,1,2,0,1);
  frame->SetStats(0);
  frame->GetXaxis()->SetTitle("x");
  frame->GetYaxis()->SetTitle("y");
  frame->Draw();

  float x[3],y[3];
  x[0] = 0.1;
  y[0] = 0.1;

  x[1] = 0.5;
  y[1] = 0.2;

  x[2] = 0.9;
  y[2] = 0.9;

  TGraph *graph = new TGraph(3,x,y);
  graph->SetLineWidth(2);
  graph->SetMarkerColor(2);
  graph->SetMarkerStyle(20);
  graph->Draw("CP");
}
