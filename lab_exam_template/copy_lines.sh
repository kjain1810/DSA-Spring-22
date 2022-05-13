if [ $# -ne 5 ]; then
  echo "Usage: sh ./copy_lines.sh <source_file> <start_line> <end_line> <target_file> <target_line>"
  exit 2
fi

source_file=$1
start_line=$2
end_line=$3
target_file=$4
target_line=$5

# check source file exists

echo -n "Checking source file..."
if test -f $source_file; then
  echo "OK"
else
  echo "does not exit"
  exit 2
fi

# check target file exists

echo -n "Checking target file..."
if test -f $target_file; then
  echo "OK"
else
  echo "does not exist"
  exit 2
fi

# check source file length

echo -n "Checking source file length..."

tmp=$(wc $source_file)
lines=$(echo $tmp|cut -d' ' -f1)

if [ $lines -ge $end_line ] && [ $end_line -ge $start_line ] && [ $start_line -ge 1 ]; then
  echo "OK"
else
  echo "improper"
  exit 2
fi

# check target file length

echo -n "Checking target file length..."

tmp=$(wc $target_file)
lines=$(echo $tmp|cut -d' ' -f1)

if [ $lines -ge $target_line ]; then
  echo "OK"
else
  echo "improper"
  exit 2
fi

awk 'NR == FNR { if(FNR >= $start_line && FNR <= $end_line) { patch = patch $0 ORS }; next } FNR == $target_line { $0 = patch $0 } 1' $source_file $target_file

echo "Done"

