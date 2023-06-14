for file in *.bmp; do
  ffmpeg -i "$file" -vcodec copy -acodec copy output.mp4
done
