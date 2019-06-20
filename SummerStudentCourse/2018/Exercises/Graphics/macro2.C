// Second example presented in "The ROOT graphics functionalities"

void macro2(){
   TH2F *h = new TH2F("h","Option COL example ",300,-4,4,300,-20,20);
   h->SetStats(0);
   h->SetContour(200);
   float px, py;
   for (int i = 0; i < 25000000; i++) {
      gRandom->Rannor(px,py);
      h->Fill(px-1,5*py);
      h->Fill(2+0.5*px,2*py-10.,0.1);
   }
   h->Draw("colz");
}
