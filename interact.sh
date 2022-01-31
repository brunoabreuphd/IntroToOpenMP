srun --partition=shared --pty --account=nsa108 --nodes=1 --ntasks-per-node=1 --cpus-per-task=16 --contiguous --mem=30G -t 02:00:00 --wait=0 --export=ALL /bin/bash
