#!/usr/bin/env bash
INFILE="$1"
shift
from=1
while true; do
  n_sep_out=$(( from-1 + $(tail -n +$from "$INFILE" | grep -m 1 -n -- '^═════$' - | cut -f1 -d:) ))

  echo "[    Your answer]"
  $@ < <(sed -n "$from,$((n_sep_out-1))p" "$INFILE")
  echo

  echo "[Expected answer]"
  a=$(tail -n +$from "$INFILE" | grep -m 1 -n -- '^─────$' - | cut -f1 -d:)
  if [ -z $a ]; then
    sed -n "$((n_sep_out+1)),\$p" "$INFILE"
    echo
    break
  else
    sed -n "$((n_sep_out+1)),$(( from -1 +a -1 ))p" "$INFILE"
    echo
    echo '---'
    from=$(( from +a ))
  fi
done
