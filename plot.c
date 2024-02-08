#include <TCanvas.h>
#include <TGraph.h>

void plot() {
     
     // Create a canvas to display the graph
     gStyle->SetOptFit();
     TCanvas *canvas = new TCanvas("canvas", "Graph", 800, 600); 
     TCanvas *canvas_1 = new TCanvas("canvas_1", "Graph_1", 800, 600);      

    // Data
     const int n = 11;
     double thickness[n] = {0.10,0.12,0.14,0.16,0.18,0.20,0.22,0.24,0.26,0.28,0.30};
     //double evnt[n] = {540,534,535,483,547,539,563,556,543,532,538};
     //double thickness[n] = {0.10,0.12,0.14,0.16,0.18,0.20,0.22,0.24,0.26,0.28,0.30};
     const int beam= 5;
     if (beam == 1){
        double evnt[n] = {5042,5177,5129,5042,5223,5125,5079,4949,5029,4983,4984};
        double thickness_1[n] = {0.10,0.12,0.14,0.16,0.18,0.20,0.22,0.24,0.26,0.28,0.30};

        double eff[n] = {0.005042,0.005177,0.005129,0.005042,0.005223,0.005125,0.005079,0.004949,0.005029,0.004983,0.004984};
        Double_t ex_1[n] = {.0000,.0000,.0000,.0000,.0000,.0000,.0000,.0000,.0000,.0000,0.0000};
        Double_t ey_1[n] = {.000001,.000001,.000001,.000001,.000001,000001,.000001,0.000001,.000001,.000001,.000001};

        Double_t ex[n] = {.00,.0,.00,.00,.00,.00,.00,.00,.00,.00,0.00};
        Double_t ey[n] = {.08108,.13131,.13013,.13458,.13587,.13029,.13452,0.13545,.13307,.13123,.13892};

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
        canvas->cd();
        graph->Draw("apl*");  // "AP" option specifies drawing with markers (points) and connecting with lines
        graph->SetMarkerColor(kBlue);
        graph->SetMarkerSize(1);
        

        // Draw the graph
        canvas_1->cd();
        graph_1->Draw("apl");  // "AP" option specifies drawing with markers (points) and connecting with lines
        graph_1->SetMarkerColor(kBlue);
        graph_1->SetMarkerSize(3);
        canvas_1->Draw();
     }
     else if (beam == 5){
        double evnt[n] = {4535,4427,4486,4456,4414,4407,4406,4499,4487,4309,4356};
        double thickness_1[n] = {0.10,0.12,0.14,0.16,0.18,0.20,0.22,0.24,0.26,0.28,0.30};

        double eff[n] = {0.004535,0.004427,0.004486,0.004456,0.004414,0.004407,0.004406,0.004499,0.004487,0.004309,0.004356};
        Double_t ex_1[n] = {.0000,.0000,.0000,.0000,.0000,.0000,.0000,.0000,.0000,.0000,0.0000};
        Double_t ey_1[n] = {.000001,.000001,.000001,.000001,.000001,000001,.000001,0.000001,.000001,.000001,.000001};

        Double_t ex[n] = {.00,.0,.00,.00,.00,.00,.00,.00,.00,.00,0.00};
        Double_t ey[n] = {.06584,.06641,0.19815,.06668,0.11677,.064895,0.06504,0.12648,0.068962,0.06698,0.06885};

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
        canvas->cd();
        graph->Draw("apl*");  // "AP" option specifies drawing with markers (points) and connecting with lines
        graph->SetMarkerColor(kBlue);
        graph->SetMarkerSize(1);


        // Draw the graph
        canvas_1->cd();
        graph_1->Draw("apl*");  // "AP" option specifies drawing with markers (points) and connecting with lines
        graph_1->SetMarkerColor(kBlack);
        graph_1->SetMarkerSize(1);
        canvas_1->Draw();
     }

}

