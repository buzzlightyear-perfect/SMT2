<!DOCTYPE html>
<html>
<head>
    <title>Kalkulator Sisa Pembagian</title>
</head>
<body>
    <h3>Masukkan Angka</h3>
    <form method="post">
        Angka 1: <input type="number" name="angka1" required><br><br>
        Angka 2: <input type="number" name="angka2" required><br><br>
        <input type="submit" value="Hitung Sisa Bagi">
    </form>

    <hr>
    <h3>Hasil Perhitungan</h3>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $angka1 = $_POST['angka1'];
        $angka2 = $_POST['angka2'];

        if ($angka2 == 0) {
            echo "Angka 2 tidak boleh nol!";
        } else {
            $hasil = $angka1 % $angka2;
            echo "$angka1 % $angka2 = $hasil";
        }
    }
    ?>
</body>
</html>