# Aplikacja do adnotacji wideo

- Pozwala na odtwarzanie wideo z adnotacjami  oraz dodawanie różnego rodzaju adnotacji w wybranych momentach. 
- Pierwszy rodzaj adnotacji to przeźroczyste okno wyskakujące na pewien czas w określonym regionie. Okno zawiera tekst, link, zdjęcie lub podobne elementy (podobne do tego co możemy znaleźć na YouTube).
- Drugi rodzaj to napisy. Nie posiadają one tła i są zazwyczaj umieszczone dolnej części wideo.
- Ostatni rodzaj to interaktywne pytania. Pytania takie zatrzymują odtwarzanie wideo i po wybraniu opcji przykładowo przechodzą do innej sekcji filmu. Przy użyciu pytań można dynamicznie sterować tym co użytkownik zobaczy w danym filmie.
- Aplikacja umożliwia przechowywanie adnotacji w specyficznym dla aplikacji formacie.
- (*) Możliwe jest odtwarzanie wideo dostępnego online (np.: z YouTube)


Wymagane pakiety do obsługi video w QT:

sudo apt-get install qtmultimedia5-dev libqt5multimediawidgets5 libqt5multimedia5-plugins libqt5multimedia5

sudo apt-get install libgstreamer1.0-0 gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly gstreamer1.0-libav gstreamer1.0-doc gstreamer1.0-tools gstreamer1.0-x gstreamer1.0-alsa gstreamer1.0-gl gstreamer1.0-gtk3 gstreamer1.0-qt5 gstreamer1.0-pulseaudio
