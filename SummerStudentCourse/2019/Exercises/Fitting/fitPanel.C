{

TH1F h("myHisto", "Barely filled histogram", 128, -8, 8);
h.FillRandom("gaus", 128);
h.Draw();

std::cout << "Start a fit panel by clicking Tools -> FitPanel" << std::endl;
}
