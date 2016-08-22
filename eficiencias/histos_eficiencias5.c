void histos_eficiencias5()
{

//gROOT->LoadMacro("tdrstyle.C");
//	setTDRStyle();


	ifstream barrel, endcap, re4;

	barrel.open("eficiencias_barrel5.txt");
  	endcap.open("eficiencias_endcap5.txt");
  	re4.open("eficiencias_re45.txt");
          cout<<"Open succesful"<<endl;

	// The Variables
	string rollName;
	double efi, efi1, efi2, efi3, efi4, knee, knee01;

	// Histos
	TH1F* efiBAR = new TH1F("Efficiency knee+480V",  "Barrel Efficiency", 30, 55, 115);
	TH1F* efi1BAR = new TH1F("Efficiency knee+500V", "Barrel Efficiency", 30, 55, 115);
	TH1F* efi2BAR = new TH1F("Efficiency knee+520V", "Barrel Efficiency", 30, 55, 115);
	TH1F* efi3BAR = new TH1F("Efficiency knee+540V", "Barrel Efficiency", 30, 55, 115);
	TH1F* efi4BAR = new TH1F("Efficiency knee+560V", "Barrel Efficiency", 30, 55, 115);

	TH1F* efiEND = new TH1F("Efficiency knee+480V",  "Endcap Efficiency", 30, 55, 115);
	TH1F* efi1END = new TH1F("Efficiency knee+500V", "Endcap Efficiency", 30, 55, 115);
	TH1F* efi2END = new TH1F("Efficiency knee+520V", "Endcap Efficiency", 30, 55, 115);
	TH1F* efi3END = new TH1F("Efficiency knee+540V", "Endcap Efficiency", 30, 55, 115);
	TH1F* efi4END = new TH1F("Efficiency knee+560V", "Endcap Efficiency", 30, 55, 115);

	TH1F* efiRE4 = new TH1F("Efficiency knee+480V",  "RE4 Efficiency", 30, 55, 115);
	TH1F* efi1RE4 = new TH1F("Efficiency knee+500V", "RE4 Efficiency", 30, 55, 115);
	TH1F* efi2RE4 = new TH1F("Efficiency knee+520V", "RE4 Efficiency", 30, 55, 115);
	TH1F* efi3RE4 = new TH1F("Efficiency knee+540V", "RE4 Efficiency", 30, 55, 115);
	TH1F* efi4RE4 = new TH1F("Efficiency knee+560V", "RE4 Efficiency", 30, 55, 115);

	TH1F* kneeBAR = new TH1F("knee for Barrel", "Knee", 70, 8.6, 10);
	TH1F* kneeEND = new TH1F("knee for Endcap", "Knee", 70, 8.6, 10);
	TH1F* kneeRE4 = new TH1F("knee for RE4", "Knee ", 70, 8.6, 10);


	// Read the data
	while(1)
	{
		barrel>>rollName>>efi>>efi1>>efi2>>efi3>>efi4>>knee>>knee01;
		if (!barrel.good()) break;
	
			efiBAR->Fill(efi);
			efi1BAR->Fill(efi1);
			efi2BAR->Fill(efi2);
			efi3BAR->Fill(efi3);
			efi4BAR->Fill(efi4);
			kneeBAR->Fill(knee);
			

	}

	while(1)
	{
		endcap>>rollName>>efi>>efi1>>efi2>>efi3>>efi4>>knee>>knee01;
		if (!endcap.good()) break;
	
			efiEND->Fill(efi);
			efi1END->Fill(efi1);
			efi2END->Fill(efi2);
			efi3END->Fill(efi3);
			efi4END->Fill(efi4);
			kneeEND->Fill(knee);
			

	}

	while(1)
	{
		re4>>rollName>>efi>>efi1>>efi2>>efi3>>efi4>>knee>>knee01;
		if (!re4.good()) break;
	
			efiRE4->Fill(efi);
			efi1RE4->Fill(efi1);
			efi2RE4->Fill(efi2);
			efi3RE4->Fill(efi3);
			efi4RE4->Fill(efi4);
			kneeRE4->Fill(knee);
			

	}

	

	

	// Canvas
	TCanvas* MyCanvas = new TCanvas("My Canvas","My Canvas", 1024, 768);
	MyCanvas->SetGrid(1, 1);
	MyCanvas->SetTicks(1, 1);
	TPad *Pad1 = new TPad("Pad1", "The pad 100% of the height", 0.0, 0.0, 1.0, 1.0, 0);
	Pad1->Draw();
	Pad1->SetGrid(1, 1);
	Pad1->SetTicks(1, 1);


	// Draw the histos
	// knee
	Pad1->cd();
	gStyle->SetOptStat(1111);
	Title(kneeBAR, "Knee", "Knee (HV)", "Events", 1.2);
	Format(kneeBAR, 2, 2, 0, 0);
	DrawWithOFUF(kneeBAR, 0, 0);
	Format(kneeEND, 2, 4, 0, 0);
	DrawWithOFUF(kneeEND, 0, 1);
	Format(kneeRE4, 2, 3, 0, 0);
	DrawWithOFUF(kneeRE4, 0, 2);
	// Legend
	Legend3(0.12, 0.75, 0.28, 0.88,
		"knee",
		kneeBAR, "knee_Barrel",
		kneeEND, "knee_Endcap",
		kneeRE4, "knee_RE4",
		0.028);

	MyCanvas->SaveAs("histogramas_5/knee5.png");

	// Barrel Efficiency
	Pad1->cd();
	gStyle->SetOptStat(1111);
	Title(efiBAR, "Barrel Efficiency", "Efficiency", "Events", 1.2);
	Format(efiBAR, 2, 4, 0, 0);
	DrawWithOFUF(efiBAR, 0, 0);
    	Format(efi1BAR, 2, 2, 0, 0);
    	DrawWithOFUF(efi1BAR, 0, 1);
	Format(efi2BAR, 2, 3, 0, 0);
	DrawWithOFUF(efi2BAR, 0, 2);
	Format(efi3BAR, 2, 5, 0, 0);
	DrawWithOFUF(efi3BAR, 0, 3);
	Format(efi4BAR, 2, 6, 0, 0);
	DrawWithOFUF(efi4BAR, 0, 4);
	// Legend
	Legend5(0.12, 0.70, 0.30, 0.88,
		"effwp",
		efiBAR, "knee+480V",
		efi1BAR, "knee+500V",
		efi2BAR, "knee+520V",
		efi3BAR, "knee+540V",
		efi4BAR, "knee+560V",
		0.030);

	//Pad1->SetLogy();
	MyCanvas->SaveAs("histogramas_5/effbarrel5.png");


	// Endcap Efficiency
	Pad1->cd();
	gStyle->SetOptStat(1111);
	Title(efiEND, "Endcap Efficiency", "Efficiency", "Events", 1.2);
	Format(efiEND, 2, 4, 0, 0);
	DrawWithOFUF(efiEND, 0, 0);
    	Format(efi1END, 2, 2, 0, 0);
    	DrawWithOFUF(efi1END, 0, 1);
	Format(efi2END, 2, 3, 0, 0);
	DrawWithOFUF(efi2END, 0, 2);
	Format(efi3END, 2, 5, 0, 0);
	DrawWithOFUF(efi3END, 0, 3);
	Format(efi4END, 2, 6, 0, 0);
	DrawWithOFUF(efi4END, 0, 4);
	// Legend
	Legend5(0.12, 0.70, 0.30, 0.88,
		"effwp",
		efiEND, "knee+480V",
		efi1END, "knee+500V",
		efi2END, "knee+520V",
		efi3END, "knee+540V",
		efi4END, "knee+560V",
		0.030);

	MyCanvas->SaveAs("histogramas_5/effendcap5.png");

	// RE4 Efficiency
	Pad1->cd();
	gStyle->SetOptStat(1111);
	Title(efiRE4, "RE4 Efficiency", "Efficiency", "Events", 1.2);
	Format(efiRE4, 2, 4, 0, 0);
	DrawWithOFUF(efiRE4, 0, 0);
    	Format(efi1RE4, 2, 2, 0, 0);
    	DrawWithOFUF(efi1RE4, 0, 1);
	Format(efi2RE4, 2, 3, 0, 0);
	DrawWithOFUF(efi2RE4, 0, 2);
	Format(efi3RE4, 2, 5, 0, 0);
	DrawWithOFUF(efi3RE4, 0, 3);
	Format(efi4RE4, 2, 6, 0, 0);
	DrawWithOFUF(efi4RE4, 0, 4);
	// Legend
	Legend5(0.12, 0.70, 0.30, 0.88,
		"effwp",
		efiRE4, "knee+480V",
		efi1RE4, "knee+500V",
		efi2RE4, "knee+520V",
		efi3RE4, "knee+540V",
		efi4RE4, "knee+560V",
		0.030);

	MyCanvas->SaveAs("histogramas_5/effRE45.png");
	//MyCanvas->SetLogy();
	//MyCanvas->SaveAs("histogramas/effRE4log.png");



	endcap.close();
	barrel.close();
	re4.close();


}

void Title(TH1F* Hist, char* Title, char* XTitle, char* YTitle, float TitleOffset)
{
	Hist->SetTitle(Title);
	Hist->GetXaxis()->SetTitle(XTitle);
	Hist->GetXaxis()->CenterTitle();	
	// Hist->GetXaxis()->SetTitleOffset(TitleOffset);
	Hist->GetYaxis()->SetTitle(YTitle);
	Hist->GetYaxis()->CenterTitle();
	Hist->GetYaxis()->SetTitleOffset(TitleOffset);
}

void Format(TH1F* Hist, int LineWidth, int LineColor, int FillStyle, int FillColor)
{
	Hist->SetLineWidth(LineWidth);
	Hist->SetLineColor(LineColor);
	Hist->SetFillStyle(FillStyle);
	Hist->SetFillColor(FillColor);
}

void Legend2(float x1, float y1, float x2, float y2, char* Header, TH1F* Entry1, char* Desc1, TH1F* Entry2, char* Desc2, float TextSize)
{
	Leg = new TLegend(x1, y1, x2, y2);
	Leg->AddEntry(Entry1, Desc1, "L");
	Leg->AddEntry(Entry2, Desc2, "L");
	//Leg->SetTextAlign(22);
	Leg->SetTextSize(TextSize);
	Leg->Draw();
}

void Legend3(float x1, float y1, float x2, float y2, char* Header, TH1F* Entry1, char* Desc1, TH1F* Entry2, char* Desc2, TH1F* Entry3, char* Desc3, float TextSize)
{
	Leg = new TLegend(x1, y1, x2, y2);
	Leg->AddEntry(Entry1, Desc1, "L");
	Leg->AddEntry(Entry2, Desc2, "L");	
	Leg->AddEntry(Entry3, Desc3, "L");
	//Leg->SetTextAlign(22);
	Leg->SetTextSize(TextSize);
	Leg->Draw();
}

void Legend5(float x1, float y1, float x2, float y2, char* Header, TH1F* Entry1, char* Desc1, TH1F* Entry2, char* Desc2, TH1F* Entry3, char* Desc3, TH1F* Entry4, char* Desc4, TH1F* Entry5, char* Desc5, float TextSize)
{
	Leg = new TLegend(x1, y1, x2, y2);
	Leg->AddEntry(Entry1, Desc1, "L");
	Leg->AddEntry(Entry2, Desc2, "L");	
	Leg->AddEntry(Entry3, Desc3, "L");
	Leg->AddEntry(Entry4, Desc4, "L");
	Leg->AddEntry(Entry5, Desc5, "L");
	//Leg->SetTextAlign(22);
	Leg->SetTextSize(TextSize);
	Leg->Draw();
}

void DrawWithOFUF(TH1F* Hist, bool Norm, int Same)
{
	char* Name = Hist->GetName();
	char* Title = Hist->GetTitle();

	Int_t Nx    = Hist->GetNbinsX()+2;
	Double_t BW = Hist->GetBinWidth(0);
	Double_t x1 = Hist->GetBinLowEdge(1)-BW;
	BW = Hist->GetBinWidth(Nx-1);
	Double_t x2 = Hist->GetBinLowEdge(Nx-2)+BW+BW;

	// Book a temporary histogram having extra bins for overflows and underflows
	TH1F *HTmp = new TH1F(Name, Title, Nx, x1, x2);

	// Fill the new hitogram including the extra bin for overflows
	for (Int_t i=1; i<=Nx; i++)
		HTmp->Fill(HTmp->GetBinCenter(i), Hist->GetBinContent(i-1));

	// Restore the number of entries
	HTmp->SetEntries(Hist->GetEntries());

	// Make title and format same as original
	Title(HTmp, Hist->GetTitle(), Hist->GetXaxis()->GetTitle(), Hist->GetYaxis()->GetTitle(), Hist->GetYaxis()->GetTitleOffset());
	Format(HTmp, Hist->GetLineWidth(), Hist->GetLineColor(), Hist->GetFillStyle(), Hist->GetFillColor());

	HTmpIntgrl = HTmp->Integral();
	if(Norm)
		HTmp->Scale(1/HTmpIntgrl);
	HTmp->GetYaxis()->SetRangeUser(HTmp->GetMinimum()*1.2, HTmp->GetMaximum()*1.2);

	// Draw the temporary histogram
	if(Same==4)
	{
		HTmp->Draw("sames");
		// StatBox
		//gPad->SetLogy();
		gPad->Update();
		TPaveStats* St5 = (TPaveStats*) HTmp->FindObject("stats");
		St5->SetX1NDC(0.74);
		St5->SetX2NDC(0.88);
		St5->SetY1NDC(0.15);
		St5->SetY2NDC(0.28);
	}
	else if(Same==3)
	{
		HTmp->Draw("sames");
		// StatBox
		gPad->Update();
		TPaveStats* St4 = (TPaveStats*) HTmp->FindObject("stats");
		St4->SetX1NDC(0.74);
		St4->SetX2NDC(0.88);
		St4->SetY1NDC(0.30);
		St4->SetY2NDC(0.43);
	}
	else if(Same==2)
	{
		HTmp->Draw("sames");
		// StatBox
		gPad->Update();
		TPaveStats* St3 = (TPaveStats*) HTmp->FindObject("stats");
		St3->SetX1NDC(0.74);
		St3->SetX2NDC(0.88);
		St3->SetY1NDC(0.45);
		St3->SetY2NDC(0.58);
	}
	else if(Same==1)
	{
		HTmp->Draw("sames");
		// StatBox
		gPad->Update();
		TPaveStats* St2 = (TPaveStats*) HTmp->FindObject("stats");
		St2->SetX1NDC(0.74);
		St2->SetX2NDC(0.88);
		St2->SetY1NDC(0.60);
		St2->SetY2NDC(0.73);
	}
	else if (Same==0)
	{
		HTmp->Draw();
		// Overflow Text
		TText *Tex = new TText(x2-BW/2, Hist->GetBinContent(Nx)+20, "Overflow");
		Tex->SetTextAngle(90);
		Tex->SetTextAlign(12);
		Tex->SetTextSize(0.03);
		Tex->SetTextColor(1);
		Tex->Draw();
		// Underflow Text
		TText *Tex2 = new TText(x1+BW/2, Hist->GetBinContent(0)+20, "Underflow");
		Tex2->SetTextAngle(90);
		Tex2->SetTextAlign(12);
		Tex2->SetTextSize(0.03);
		Tex2->SetTextColor(1);
		Tex2->Draw();
		// StatBox
		gPad->Update();
		TPaveStats* St1 = (TPaveStats*) HTmp->FindObject("stats");
		St1->SetX1NDC(0.74);
		St1->SetX2NDC(0.88);
		St1->SetY1NDC(0.75);
		St1->SetY2NDC(0.88);
	}


}


