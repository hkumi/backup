#include <TCanvas.h>
#include <TGraph.h>

void plot() {
     
     // Create a canvas to display the graph
     gStyle->SetOptFit();
     TCanvas *canvas = new TCanvas("canvas", "Graph", 800, 600); 
     TCanvas *canvas_1 = new TCanvas("canvas_1", "Graph", 800, 600);      

    // Data
     const int n = 11;
     //double thickness[n] = {0.10,0.12,0.14,0.16,0.18,0.20,0.22,0.24,0.26,0.28,0.30};
     //double evnt[n] = {497,493,528,547,545,530,501,545,489,505,483};
     double thickness[n] = {0.10,0.12,0.14,0.16,0.18,0.20,0.22,0.24,0.26,0.28,0.30};
     double evnt[n] = {4930,4904,5077,4819,4901,4925,4775,4814,4873,4786,4886};
     double thickness_1[n] = {0.10,0.12,0.14,0.16,0.18,0.20,0.22,0.24,0.26,0.28,0.30};

     double eff[n] = {0.004930,0.004904,0.005077,0.004819,0.004901,0.004925,0.004775,0.004814,0.004873,0.004786,0.004886};
     Double_t ex_1[n] = {.0000,.0000,.0000,.0000,.0000,.0000,.0000,.0000,.0000,.0000,0.0000};
     Double_t ey_1[n] = {.000001,.000001,.000001,.000001,.000001,.000001,.000001,.000001,.000001,.000001,.000001};



     Double_t ex[n] = {.00,.0,.00,.00,.00,.00,.00,.00,.00,.00,0.00};
     Double_t ey[n] = {.01,.01,.01,.01,.01,.01,.01,.01,.01,.01,.01};

    // Create a TGraph object
     TGraphErrors *graph = new TGraphErrors(n, thickness, evnt,ex,ey);
     TGraphErrors *graph_1 = new TGraphErrors(n, thickness_1, eff,ex_1,ey_1);

     // Set the graph title and axis labels
     graph->SetTitle("Graph of evnt vs thickness");
     graph->GetXaxis()->SetTitle("thickness");
     graph->GetYaxis()->SetTitle("evnt");

    // set graph for efficiency
     graph_1->SetTitle("Efficiency vs thickness");
     graph_1->GetXaxis()->SetTitle("thickness");
     graph_1->GetYaxis()->SetTitle("efficiency");

     // Draw the graph
     graph->Draw("apl*");  // "AP" option specifies drawing with markers (points) and connecting with lines
     graph->SetMarkerColor(kBlue);
     graph->SetMarkerSize(0.5);
     // Draw grap two. 

      // Draw the graph
     graph_1->Draw("apl*");  // "AP" option specifies drawing with markers (points) and connecting with lines
     graph_1->SetMarkerColor(kBlue);
     graph_1->SetMarkerSize(0.5);

     canvas->Update();
     TPaveStats *st = (TPaveStats*)graph->FindObject("stats");
 
     canvas->Modified();
     canvas_1->Draw();
     canvas->Draw();
}

