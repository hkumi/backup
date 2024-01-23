#include <TCanvas.h>
#include <TGraph.h>

void plot() {
     
     // Create a canvas to display the graph
     gStyle->SetOptFit();
     TCanvas *canvas = new TCanvas("canvas", "Graph", 800, 600); 
     TCanvas *canvas_1 = new TCanvas("canvas_1", "Graph", 800, 600);      

    // Data
     const int n = 11;
     double thickness[n] = {0.10,0.12,0.14,0.16,0.18,0.20,0.22,0.24,0.26,0.28,0.30};
     //double evnt[n] = {540,534,535,483,547,539,563,556,543,532,538};
     //double thickness[n] = {0.10,0.12,0.14,0.16,0.18,0.20,0.22,0.24,0.26,0.28,0.30};
     double evnt[n] = {4654,4950,4920,4999,5015,5083,4922,5019,5184,4677,4988};
     double thickness_1[n] = {0.10,0.12,0.14,0.16,0.18,0.20,0.22,0.24,0.26,0.28,0.30};

     double eff[n] = {0.004654,0.004950,0.004920,0.004999,0.005015,0.005083,0.004922,0.005019,0.005184,0.004677,0.004988};
     Double_t ex_1[n] = {.0000,.0000,.0000,.0000,.0000,.0000,.0000,.0000,.0000,.0000,0.0000};
     Double_t ey_1[n] = {.000001,.000001,.000001,.000001,.000001,.000001,.000001,.000001,.000001,.000001,.000001};



     Double_t ex[n] = {.00,.0,.00,.00,.00,.00,.00,.00,.00,.00,0.00};
     Double_t ey[n] = {.01719,.01914,.02457,.01418,.01918,.01969,.01715,.01805,.01505,.02353,.01505};

    // Create a TGraph object
     TGraphErrors *graph = new TGraphErrors(n, thickness, evnt,ex,ey);
     TGraphErrors *graph_1 = new TGraphErrors(n, thickness_1, eff,ex_1,ey_1);

     // Set the graph title and axis labels
     graph->SetTitle("Graph of evnt vs thickness");
     graph->GetXaxis()->SetTitle("thickness[mm]");
     graph->GetYaxis()->SetTitle("evnt");

    // set graph for efficiency
     //graph_1->SetTitle("Efficiency vs thickness");
     //graph_1->GetXaxis()->SetTitle("thickness[mm]");
     //graph_1->GetYaxis()->SetTitle("efficiency");

     // Draw the graph
     graph->Draw("apl*");  // "AP" option specifies drawing with markers (points) and connecting with lines
     graph->SetMarkerColor(kBlue);
     graph->SetMarkerSize(0.5);
     // Draw grap two. 

      // Draw the graph
     //graph_1->Draw("apl*");  // "AP" option specifies drawing with markers (points) and connecting with lines
     //graph_1->SetMarkerColor(kBlue);
     //graph_1->SetMarkerSize(0.5);

     
     canvas_1->Draw();
     canvas->Draw();
}

