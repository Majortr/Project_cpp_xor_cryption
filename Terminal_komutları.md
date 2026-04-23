1) Branch nedir?

main ana daldır.
Projede çalışan, daha “resmi” sürüm gibi düşün.

Branch ise bundan ayrılan çalışma koludur.

Örnek:

main → ana sürüm
feature-login → giriş ekranı çalışması
feature-menu → menü çalışması

Yani herkes kendi işini ayrı dalda yapar.
İş bitince ana projeye geri birleştirilir.

2) Neden branch kullanmalısınız?

İkiniz de direkt main üzerinde çalışırsanız:

gereksiz conflict artar
kimin neyi bozduğu karışabilir
yarım işleri ana sürüme atmış olursunuz

Branch kullanırsanız:

her kişi izole çalışır
bitmeyen işi maine sokmaz
birleştirme kontrollü olur

Bu, ekip çalışmasının standart yöntemidir.

3) Sizin için önerdiğim yapı

İki kişilik proje için en pratik yapı:

main → çalışan ana sürüm
senin branch’in → örn. feature-encryption
arkadaşının branch’i → örn. feature-ui

Yani herkes kendi branch’inde çalışsın.

4) Yeni branch nasıl açılır?

Önce projede olduğundan emin ol:

cd Project_cpp_cryption

Sonra mevcut branch’i kontrol et:

git branch

Yıldızlı olan aktif branch’tir.

Yeni branch aç ve ona geç

Örneğin sen:

git checkout -b feature-encryption

Arkadaşın:

git checkout -b feature-ui

Bu komut iki işi birden yapar:

branch oluşturur
o branch’e geçer
5) Branch’i GitHub’a gönderme

Yeni branch açtıktan sonra GitHub’a da göndermen gerekir:

git push -u origin feature-encryption

Arkadaşın için:

git push -u origin feature-ui

Buradaki -u şunu yapar:
bundan sonraki push/pull işlemlerini bu branch ile eşler.

6) Günlük çalışma akışı branch ile nasıl olur?

Diyelim sen feature-encryption branch’indesin.

Çalışmaya başlamadan önce

Önce branch’inde olduğundan emin ol:

git branch

Gerekirse branch’e geç:

git checkout feature-encryption

Sonra güncel durumu al:

git pull
Kod yazdıktan sonra
git add .
git commit -m "Şifreleme fonksiyonu eklendi"
git push

Arkadaşın da kendi branch’inde aynı mantıkla çalışır.

7) Branch değiştirme

Projede hangi branch’te olduğunuzu değiştirmek için:

git checkout main

veya

git checkout feature-encryption

Arkadaşın için:

git checkout feature-ui
8) Hangi branch’ler var görmek

Hem yerel branch’leri görmek için:

git branch

Hem uzak repo branch’lerini de görmek için:

git branch -a
9) Branch ile çalışma sırasında en doğru alışkanlık

Her yeni görev için ayrı branch açın.

Örnek görev adları:

feature-login
feature-file-read
feature-aes
bugfix-memory-error

Böyle branch isimleri düzenli olur.

10) İş bitince main’e nasıl alınır?

Bunun iki yolu var:

Yol A — GitHub üzerinden Pull Request

En temiz ve önerilen yöntem bu.

Sen branch’ini push ettikten sonra GitHub’da genelde şunu görürsün:

Compare & pull request

Oradan:

feature-encryption → main
şeklinde Pull Request açarsın.

Sonra:

değişiklikleri kontrol edersiniz
Merge pull request
Confirm merge

Böylece branch’teki iş maine eklenir.

Yol B — Terminalden merge

Bu da olur ama başlangıçta GitHub üzerinden gitmek daha net.

11) Pull Request mantığı

Pull Request şu demek:

“Ben kendi branch’imde yaptığım işi ana projeye eklemek istiyorum. Önce kontrol edin, sonra birleştirelim.”

İki kişi çalışırken çok faydalıdır çünkü:

ne değiştiği görünür
yorum yapılabilir
kontrollü merge olur
12) Size önerdiğim gerçek çalışma senaryosu

Diyelim görev paylaşımı yaptınız:

sen: şifreleme kısmı
arkadaşın: arayüz kısmı
Sen
git checkout main
git pull
git checkout -b feature-encryption
git push -u origin feature-encryption

Sonra çalış:

git add .
git commit -m "XOR şifreleme altyapısı eklendi"
git push
Arkadaşın
git checkout main
git pull
git checkout -b feature-ui
git push -u origin feature-ui

Sonra çalış:

git add .
git commit -m "Menü arayüzü eklendi"
git push

Sonra ikiniz ayrı ayrı Pull Request açarsınız.

13) Neden önce maine dönüp git pull yapıyoruz?

Yeni branch açmadan önce ana branch’in güncel olması gerekir.
Yoksa eski bir temel üzerinden branch açmış olursun.

Doğru sıra çoğu zaman şudur:

git checkout main
git pull
git checkout -b yeni-branch

Bu çok önemli bir alışkanlık.

14) Merge conflict ne zaman olur?

İkiniz de aynı dosyanın aynı satırlarını değiştirirseniz olur.

Örnek:

sen main.cpp içinde aynı fonksiyonu değiştiriyorsun
arkadaşın da aynı fonksiyonu değiştiriyor

Sonra merge sırasında Git hangisini alacağını bilemez.

Bunu azaltmak için:

görevleri bölün
aynı dosyanın farklı kısımlarını alın
küçük ve sık commit atın
15) Güvenli branch düzeni

Size şu kuralları öneriyorum:

main branch’ine direkt büyük geliştirme yapmayın
herkes kendi branch’inde çalışsın
main sadece çalışan sürüm olsun
iş bitince Pull Request ile birleştirin

Bu yöntem çok daha temizdir.

16) En çok kullanacağınız branch komutları
Yeni branch aç
git checkout -b feature-adi
Branch değiştir
git checkout main
Branch’leri gör
git branch
Uzak branch’e ilk push
git push -u origin feature-adi
17) Sizin için önerdiğim tam akış

Her yeni görevde:

git checkout main
git pull
git checkout -b feature-gorev-adi
git push -u origin feature-gorev-adi

Çalışırken:

git add .
git commit -m "Görevi açıkla"
git push

İş bitince:

GitHub’a gir
Pull Request aç
Merge et
18) Branch silme

İşiniz bittikten ve merge olduktan sonra branch’i silebilirsiniz.

Yerelde silmek:

git branch -d feature-encryption

Uzakta silmek:

git push origin --delete feature-encryption

Ama başlangıçta hemen silmek zorunda değilsiniz.

19) Size özel kısa özet

İkiniz için doğru yöntem:

main güncel tutulur
herkes kendi branch’ini açar
kendi branch’inde çalışır
push yapar
GitHub’da Pull Request açar
maine merge edilir
20) İlk deneme için tam komutlar

Sen:

git checkout main
git pull
git checkout -b feature-encryption
git push -u origin feature-encryption

Arkadaşın:

git checkout main
git pull
git checkout -b feature-ui
git push -u origin feature-ui

Sonra herkes kendi branch’inde iş yapıp:

git add .
git commit -m "Yaptığı iş"
git push
21) Sana tavsiyem

İlk etapta branch isimlerini basit koyun:

feature-efehan
feature-samege

Böylece karışmaz.

Daha sonra göreve göre isimlendirirsiniz.

İstersen bir sonraki mesajda size GitHub üzerinde Pull Request açmayı ve merge etmeyi adım adım, görsel mantıkla anlatayım.