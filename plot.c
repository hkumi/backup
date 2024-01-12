#include <TCanvas.h>
#include <TGraph.h>

void plot() {
     
     // Create a canvas to display the graph
     gStyle->SetOptFit();
     TCanvas *canvas = new TCanvas("canvas", "Graph", 800, 600);    

    // Data
     const int n = 11;
     double thickness[n] = {0.1,0.12,0.14,0.16,0.18,1.0,1.02,1.04,1.06,1.08,1.10};
     double evnt[n] = {497,493,528,547,545,533,517,490,537,529,503};
     Double_t ex[n] = {.00,.0,.00,.00,.00,.00,.00,.00,.00,.00,0.00};
     Double_t ey[n] = {.8,.7,.6,.5,.4,.4,.5,.6,.7,.8,.8};

    // Create a TGraph object
     TGraphErrors *graph = new TGraphErrors(n, thickness, evnt,ex,ey);

     // Set the graph title and axis labels
     graph->SetTitle("Graph of evnt vs thickness");
     graph->GetXaxis()->SetTitle("thickness");
     graph->GetYaxis()->SetTitle("evnt");

     // Draw the graph
     graph->Draw("apl*");  // "AP" option specifies drawing with markers (points) and connecting with lines
     graph->SetMarkerColor(kBlue);
     graph->SetMarkerSize(0.5);

     canvas->Update();
     TPaveStats *st = (TPaveStats*)graph->FindObject("stats");
 
     canvas->Modified();
}

