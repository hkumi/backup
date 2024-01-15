#include <TCanvas.h>
#include <TGraph.h>

void plot() {
     
     // Create a canvas to display the graph
     gStyle->SetOptFit();
     TCanvas *canvas = new TCanvas("canvas", "Graph", 800, 600);    

    // Data
     const int n = 11;
     //double thickness[n] = {0.10,0.12,0.14,0.16,0.18,0.20,0.22,0.24,0.26,0.28,0.30};
     //double evnt[n] = {497,493,528,547,545,530,501,545,489,505,483};
     double thickness[n] = {0.10,0.12,0.14,0.16,0.18,0.20,0.22,0.24,0.26,0.28,0.30};
     double evnt[n] = {533,535,542,572,586,562,528,543,514,594,558};

     Double_t ex[n] = {.00,.0,.00,.00,.00,.00,.00,.00,.00,.00,0.00};
     Double_t ey[n] = {.01,.01,.01,.01,.01,.01,.01,.01,.01,.01,.01};

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

