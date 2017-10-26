package LycorisNet

type Lycoris struct {
	Input       []float64
	Desire      []float64
	SpeciesList []Species
}

func NewLycoris(capacity int, inputNum int, outputNum int) *Lycoris {
	var lycoris = &Lycoris{}
	lycoris.Input = make([]float64, inputNum)
	lycoris.Desire = make([]float64, outputNum)
	var specie = Species{}
	specie.IndividualList = make([]Individual, capacity)
	for i := 0; i < capacity; i++ {
		specie.IndividualList[i] = *NewIndividual(inputNum, outputNum)
	}
	lycoris.SpeciesList = append(lycoris.SpeciesList, specie)
	return lycoris
}

func (lycoris *Lycoris) chooseElite() {
	// TODO
}

func (lycoris *Lycoris) mate() {
	// TODO
}

func (lycoris *Lycoris) mutate() {
	// TODO
}

func (lycoris *Lycoris) classify() {
	// TODO
}

func (lycoris *Lycoris) RunLycoris() {
	lycoris.chooseElite()
	lycoris.mate()
	lycoris.mutate()
}
