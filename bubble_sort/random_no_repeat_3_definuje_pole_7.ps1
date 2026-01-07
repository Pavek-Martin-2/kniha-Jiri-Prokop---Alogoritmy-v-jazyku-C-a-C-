cls

# random no repeat 3, vytvori ind pole

Remove-Variable od, do, pole, aa, bb, z -ErrorAction SilentlyContinue

$od = 0
$do = 9999 # 0-99; 0-999 apod

$polozek_na_radek = 25 # max 32 pro 999 ; max 25 pro 999

$pole = $od..$do | Get-Random -Count $do   # zamíchaný seznam

for ( $aa = 0; $aa -le $pole.Length-1; $aa=$aa+($polozek_na_radek + 1 ) ){

$z = [string] $pole[$aa] + ","

for ( $bb = 1; $bb -le $polozek_na_radek; $bb++ ) { # <=
$z += [string] $pole[$aa+$bb] + ","
}

echo $z
}

#echo $pole

#sleep 60


