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
     double evnt[n] = {5042,5177,5129,5042,5223,5125,5079,4949,5029,4983,4984};
     double thickness_1[n] = {0.10,0.12,0.14,0.16,0.18,0.20,0.22,0.24,0.26,0.28,0.30};

     double eff[n] = {0.005042,0.005177,0.005129,0.005042,0.005223,0.005125,0.005079,0.004949,0.005029,0.004983,0.004984};
     Double_t ex_1[n] = {.0000,.0000,.0000,.0000,.0000,.0000,.0000,.0000,.0000,.0000,0.0000};
     Double_t ey_1[n] = {.000001,.000001,.000001,.000001,.000001,000001,.000001,0.000001,.000001,.000001,.000001};



     Double_t ex[n] = {.00,.0,.00,.00,.00,.00,.00,.00,.00,.00,0.00};
     Double_t ey[n] = {.08108,.13131,.13013,.13458,.13587,.13029,.13452,0.13545,.13307,.13123,.13892};
    double sigma_i[n];
    for (int i = 0; i < n; ++i) {
        sigma_i[i] = sqrt(eff[i]);
        cout << sigma_i[i] << endl << endl;
    }
    double sigma_j[n];
    for (int j = 0; j < n; ++j) {
        sigma_j[j] = sqrt(thickness_1[j]);
        cout << sigma_j[j] << endl;
    }



    // Create a TGraph object
     TGraphErrors *graph = new TGraphErrors(n, thickness, evnt,ex,ey);
     TGraphErrors *graph_1 = new TGraphErrors(n, thickness_1, eff, ex_1,ex);

     // Set the graph title and axis labels
     graph->SetTitle("Graph of evnt vs thickness");
     graph->GetXaxis()->SetTitle("thickness[mm]");
     graph->GetYaxis()->SetTitle("evnt");

    // set graph for efficiency
     graph_1->SetTitle("Efficiency vs thickness");
     graph_1->GetXaxis()->SetTitle("thickness[mm]");
     graph_1->GetYaxis()->SetTitle("efficiency");

     // Draw the graph
     graph->Draw("apl*");  // "AP" option specifies drawing with markers (points) and connecting with lines
     graph->SetMarkerColor(kBlue);
     graph->SetMarkerSize(1);
     // Draw grap two. 

      // Draw the graph
   //  graph_1->Draw("apl*");  // "AP" option specifies drawing with markers (points) and connecting with lines
    // graph_1->SetMarkerColor(kBlue);
     //graph_1->SetMarkerSize(3);

     
     canvas_1->Draw();
     canvas->Draw();
}

