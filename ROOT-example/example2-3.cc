void example(double mean = 10., double wid = 2.){
  double min_x = mean-wid*5;
  double max_x = mean+wid*5;

  TF1 *f = new TF1("f","gaus",min_x,max_x);
  f->SetParameters(10,mean,wid);
  SetTF1(f,4,2,7);

  TH1D *h1 = new TH1D("h1","h1",100,min_x,max_x);   // Set titles with same method as example2-2.cc
  h1->SetTitle("Example2  h1");
  h1->GetXaxis()->SetTitle("X (mm)");
  h1->GetXaxis()->CenterTitle();
  h1->GetXaxis()->SetTitleSize(0.05);
  h1->GetXaxis()->SetTitleOffset(1.00);
  h1->GetYaxis()->SetTitle(Form("counts / %.1lf mm",(max_x-min_x)/100.));
  h1->GetYaxis()->CenterTitle();
  h1->GetYaxis()->SetTitleSize(0.05);
  h1->GetYaxis()->SetTitleOffset(1.20);
  h1->SetFillStyle(3002);
  h1->SetFillColor(3);
  h1->SetStats(kFALSE);

  TH1D *h2 = new TH1D("h2","h2",100,min_x,max_x);   // Set titles with special function
  SetTH1(h2,"Example2  h2","X (mm)",Form("counts / %.1lf mm",(max_x-min_x)/100.),1,3004,38);

  for(int i=0;i<100000;i++){
    double val = gRandom->Gaus(mean,wid);
    h1->Fill(val);
    h2->Fill(val);
  }

  double par[3], epar;
  h1->Fit(f,"0Q","",min_x,max_x);
  f->GetParameters(&par[0]);                      // Get parameters of "f"
  epar = f->GetParError(2);                       // Get an error of 3rd parameter
  cout<<Form("Constant : %e",par[0])<<endl;       // Output results in a terminal
  cout<<Form("Mean     : %lf",par[1])<<endl;
  cout<<Form("Sigma    : %.3lf",par[2])<<endl;

  double max = h1->GetMaximum();
  TLatex *t = new TLatex(par[1]+1.,max*0.95,Form("#sigma = %.3lf #pm %.3lf mm",par[2],epar));  // Set Text
  t->SetTextSize(0.04);
  t->SetTextColor(2);
  t->SetTextFont(42);

  TCanvas *c1 = new TCanvas("c1","c1",500,800);
  c1->Divide(1,2,1E-5,1E-5);
  c1->cd(1)->SetMargin(0.15,0.10,0.15,0.10);
  h2->Draw();
  c1->cd(2)->SetMargin(0.15,0.10,0.15,0.10);
  h1->Draw();
  f->Draw("same");
  t->Draw();
  c1->Print("c1.png");     // Save c1 canvas to PNG file
  c1->Print("c1.pdf");     // Save c1 canvas to PDF file
  c1->Print("c1.ps");      // Save c1 canvas to ps file
}

