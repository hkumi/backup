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
     double evnt[n] = {4638,5201,4763,4776,4944,4901,4739,5094,5078,4731,4896};
     double thickness_1[n] = {0.10,0.12,0.14,0.16,0.18,0.20,0.22,0.24,0.26,0.28,0.30};

     double eff[n] = {0.004638,0.005201,0.004763,0.004776,0.004944,0.004901,0.004739,0.005094,0.005078,0.004731,0.004896};
     Double_t ex_1[n] = {.0000,.0000,.0000,.0000,.0000,.0000,.0000,.0000,.0000,.0000,0.0000};
     Double_t ey_1[n] = {.000001,.000001,.000001,.000001,.000001,000001,.000001,0.000001,.000001,.000001,.000001};



     Double_t ex[n] = {.00,.0,.00,.00,.00,.00,.00,.00,.00,.00,0.00};
     Double_t ey[n] = {.09543,.09863,.12413,.11918,.11163,.11151,.11762,0.12142,.11078,.11381,.13169};
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
//     TGraphErrors *graph_1 = new TGraphErrors(n, thickness, evnt,ex,ey);
     TGraphErrors *graph_1 = new TGraphErrors(n, thickness_1, eff, ex_1,ex);

     // Set the graph title and axis labels
     //graph->SetTitle("Graph of evnt vs thickness");
     //graph->GetXaxis()->SetTitle("thickness[mm]");
     //graph->GetYaxis()->SetTitle("evnt");

    // set graph for efficiency
     graph_1->SetTitle("Efficiency vs thickness");
     graph_1->GetXaxis()->SetTitle("thickness[mm]");
     graph_1->GetYaxis()->SetTitle("efficiency");

     // Draw the graph
     //graph->Draw("apl*");  // "AP" option specifies drawing with markers (points) and connecting with lines
     //graph->SetMarkerColor(kBlue);
     //graph->SetMarkerSize(1);
     // Draw grap two. 

      // Draw the graph
     graph_1->Draw("apl*");  // "AP" option specifies drawing with markers (points) and connecting with lines
     graph_1->SetMarkerColor(kBlue);
     graph_1->SetMarkerSize(5);

     
     canvas_1->Draw();
     canvas->Draw();
}

