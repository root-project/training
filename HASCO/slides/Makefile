all: figures hasco_root.pdf

hasco_root.pdf: hasco_root.tex
	pdflatex hasco_root.tex

figures: figures/figure-001.pdf figures/figure-002.pdf figures/figure-003.pdf figures/figure-004.pdf figures/figure-005.pdf figures/figure-006.pdf figures/figure-007.pdf figures/figure-008.pdf figures/figure-009.pdf figures/figure-010.pdf figures/Figure_005-a.pdf figures/CMS-HIG-12-028_Figure_003.pdf figures/whats_in_aod_reco.png figures/pict1_TColorWheel_001.png figures/cpp_weekly_cppyy.jpg figures/figure-011.pdf figures/model.png figures/tefficiency_1.pdf figures/tefficiency_2.pdf figures/clad.pdf

figures/figure-%.pdf: scripts/figure%.C
	mkdir -p figures
	cd figures && root -l -b -q ../scripts/figure$*.C
	pdfcrop $@
	mv figures/figure-$*-crop.pdf $@

figures/model.png: figures/figure-011.pdf
	cd figures && dot -Tpng -o model.png model.dot

figures/tefficiency_1.pdf: scripts/tefficiency.py
	mkdir -p figures
	cd figures && python ../scripts/tefficiency.py
	pdfcrop figures/tefficiency_1.pdf
	mv figures/tefficiency_1-crop.pdf figures/tefficiency_1.pdf
	pdfcrop figures/tefficiency_2.pdf
	mv figures/tefficiency_2-crop.pdf figures/tefficiency_2.pdf

figures/clad.pdf: scripts/clad.py
	mkdir -p figures
	cd figures && python ../scripts/clad.py
	pdfcrop figures/clad.pdf
	mv figures/clad-crop.pdf figures/clad.pdf

figures/tefficiency_2.pdf: figures/tefficiency_1.pdf

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
	cd figures && rm -f figure-001.pdf figure-002.pdf figure-003.pdf figure-004.pdf figure-005.pdf figure-006.pdf figure-007.pdf figure-008.pdf figure-009.pdf figure-010.pdf Figure_005-a.pdf CMS-HIG-12-028_Figure_003.pdf whats_in_aod_reco.png pict1_TColorWheel_001.png cpp_weekly_cppyy.jpg figure-011.pdf figure-011a.pdf model.dot model.png tefficiency_1.pdf tefficiency_2.pdf clad.pdf
	rm -f hasco_root.aux
	rm -f hasco_root.listing
	rm -f hasco_root.log
	rm -f hasco_root.nav
	rm -f hasco_root.out
	rm -f hasco_root.pdf
	rm -f hasco_root.snm
	rm -f hasco_root.toc
	rm -f hasco_root.vrb
