
#Inspiration: https://www.youtube.com/watch?v=FGC5TdIiT9U&t=523s
#More on integer sequences: https://oeis.org/ "The On-Line Encyclopedia of Integer Sequences"

from mido import Message, MidiFile, MidiTrack

def timer(func):
    import time
    def f(*args, **kwargs):
        before = time.time()
        rv = func(*args, **kwargs)
        after = time.time()
        print('%s ran in %s seconds with args=%s and kwargs=%s' %(func.__name__, after-before, args, kwargs))
        return rv
    return f


def generate_midi_seq(seq,file_name, num_steps = 1000):
    # Tushar's composition
    seq = seq(num_steps)
    mid = MidiFile()
    track = MidiTrack()
    mid.tracks.append(track)
    track.append(Message('program_change', program=12, time=0))
    for i in range(num_steps):
        track.append(Message('note_on', note=seq[i]%128, velocity=50, time=seq[i]%128))
        track.append(Message('note_off', note=seq[i]%128, velocity=50, time=seq[i]%128))
    mid.save(file_name)


@timer
def generate_midi_seq(seq, file_name, num_steps = 1000):
    # Pure sequence
    seq = seq(num_steps)
    mid = MidiFile()
    track = MidiTrack()
    mid.tracks.append(track)
    track.append(Message('program_change', program=12, time=0))
    for i in range(num_steps):
        track.append(Message('note_on', note=seq[i]%128, velocity=50, time=100))
        track.append(Message('note_off', note=seq[i]%128, velocity=50, time=100))
    mid.save(file_name)


def recamanSequence(num_steps):
    recaman = [0]
    for ctr in range(1, num_steps):
        last_num = recaman[-1]
        if last_num-ctr not in recaman and last_num-ctr>0:
            recaman.append(last_num-ctr)
        else:
            recaman.append(last_num+ctr)
    return recaman


def fibonacci(num_steps):
    seq = [0, 1]
    while len(seq)<num_steps:
        seq.append(seq[-2]+seq[-1])
    return seq


def GeestSequence(num_steps=1000):
    seq=[0]
    for i in range(num_steps):
        lst = seq[-1]
        nxt = lst+1
        lst_dgts = set(str(lst))
        nxt_dgts = set(str(nxt))
        while len(nxt_dgts.intersection(lst_dgts))>0:
            nxt+=1
            nxt_dgts = set(str(nxt))
        seq.append(nxt)
    return seq


@timer
def GeestSequenceOpt(num_steps=1000):
    seq=[0]
    for i in range(num_steps):
        lst = seq[-1]
        lst_dgts = str(lst)
        d_one = lst_dgts[0]
        if d_one=='9':
            nxt = 1
        else:
            nxt = int(d_one)+1
        while nxt<=lst:
            min_dgt_not_in_lst = min([d for d in range(10) if str(d) not in lst_dgts])
            nxt = int(str(nxt)+str(min_dgt_not_in_lst))
        seq.append(nxt)
    return seq


def generate_midi_seq_geest(seq, file_name, num_steps = 1000):
    # Pure sequence
    seq = seq(num_steps)
    mid = MidiFile()
    track = MidiTrack()
    mid.tracks.append(track)
    track.append(Message('program_change', program=12, time=0))
    for i in range(num_steps):
        track.append(Message('note_on', note=(seq[i]+20)%88, velocity=50, time=80))
        track.append(Message('note_off', note=seq[i]%128, velocity=50, time=50))
    mid.save(file_name)


if __name__=='__main__':
    generate_midi_seq(file_name='music/recaman.mid', seq=recamanSequence)
    generate_midi_seq(file_name='music/fib.mid', seq=fibonacci)
    generate_midi_seq(file_name='music/geest.mid', seq=GeestSequence, num_steps=60)
    generate_midi_seq_geest(file_name='music/geest_opt.mid', seq=GeestSequenceOpt, num_steps=2000)
