all: figures hasco_2023.pdf

hasco_2023.pdf: hasco_2023.tex
	pdflatex hasco_2023.tex

figures: figures/figure-001.pdf figures/figure-002.pdf figures/figure-003.pdf figures/figure-004.pdf figures/figure-005.pdf figures/figure-006.pdf figures/figure-007.pdf figures/figure-008.pdf figures/figure-009.pdf figures/figure-010.pdf figures/Figure_005-a.pdf figures/CMS-HIG-12-028_Figure_003.pdf figures/whats_in_aod_reco.png figures/pict1_TColorWheel_001.png figures/cpp_weekly_cppyy.jpg figures/figure-011.pdf figures/model.png

figures/figure-%.pdf: scripts/figure%.C
	mkdir -p figures
	cd figures && root -l -b -q ../scripts/figure$*.C
	pdfcrop $@
	mv figures/figure-$*-crop.pdf $@

figures/model.png: figures/figure-011.pdf
	cd figures && dot -Tpng -o model.png model.dot

figures/Figure_005-a.pdf:
	cd figures && wget https://cds.cern.ch/record/2292159/files/Figure_005-a.pdf

figures/CMS-HIG-12-028_Figure_003.pdf:
	cd figures && wget "https://cms-results.web.cern.ch/cms-results/public-results/publications/HIG-12-028/CMS-HIG-12-028_Figure_003.pdf"

figures/whats_in_aod_reco.png:
	cd figures && wget "https://twiki.cern.ch/twiki/pub/CMSPublic/WorkBookDataFormats/whats_in_aod_reco.gif"
	convert figures/whats_in_aod_reco.gif figures/whats_in_aod_reco.png
	rm figures/whats_in_aod_reco.gif

figures/pict1_TColorWheel_001.png:
	cd figures && wget "https://root.cern.ch/doc/master/pict1_TColorWheel_001.png"

figures/cpp_weekly_cppyy.jpg:
	cd figures && wget "https://img.youtube.com/vi/TL83P77vZ1k/0.jpg"
	mv figures/0.jpg figures/cpp_weekly_cppyy.jpg

clean:
	cd figures && rm -f figure-001.pdf figure-002.pdf figure-003.pdf figure-004.pdf figure-005.pdf figure-006.pdf figure-007.pdf figure-008.pdf figure-009.pdf figure-010.pdf Figure_005-a.pdf CMS-HIG-12-028_Figure_003.pdf whats_in_aod_reco.png pict1_TColorWheel_001.png cpp_weekly_cppyy.jpg figure-011.pdf figure-011a.pdf model.dot model.png
	rm -f hasco_2023.aux
	rm -f hasco_2023.listing
	rm -f hasco_2023.log
	rm -f hasco_2023.nav
	rm -f hasco_2023.out
	rm -f hasco_2023.pdf
	rm -f hasco_2023.snm
	rm -f hasco_2023.toc
	rm -f hasco_2023.vrb
