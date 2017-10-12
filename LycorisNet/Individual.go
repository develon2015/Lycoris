package LycorisNet

type Individual struct {
	NodeMap       map[int]Node
	NodeSlice     []int
	GenomeMap     map[Gen]Ome
	InputNum      int
	OutputNum     int
	InnovationNum int
	NodeSum       int
	Fitness       float64
}

func NewIndividual(InputNum int, OutputNum int) *Individual {
	var individual *Individual = &Individual{InputNum: InputNum, OutputNum: OutputNum, NodeSum: 0, InnovationNum: 0}
	initialize(individual)
	return individual
}

func initialize(individual *Individual) {
	var sumNode = individual.InputNum + individual.OutputNum
	individual.NodeMap = make(map[int]Node, sumNode)
	individual.NodeSlice = make([]int, sumNode)
	for i := 0; i < individual.InputNum; i++ {
		var temp = individual.NodeSum
		individual.NodeMap[temp] = *NewNode(temp, 0)
		individual.NodeSlice[temp] = temp
		individual.NodeSum++
	}
	for i := 0; i < individual.OutputNum; i++ {
		var temp = individual.NodeSum
		individual.NodeMap[temp] = *NewNode(temp, 2)
		individual.NodeSlice[temp] = temp
		individual.NodeSum++
	}
	createGenes(individual)
}

func createGenes(individual *Individual) {
	individual.GenomeMap = make(map[Gen]Ome, individual.InputNum*individual.OutputNum)
	for i := individual.InputNum; i < individual.NodeSum; i++ {
		for j := 0; j < individual.InputNum; j++ {
			var gen = Gen{j, i}
			var ome = Ome{Random(), true, individual.InnovationNum}
			individual.GenomeMap[gen] = ome
			individual.NodeMap[i].GenomeMap[gen] = ome
			individual.InnovationNum++
		}
	}
}

func (individual *Individual) SetInput(input []float64) {
	for i := 0; i < individual.InputNum; i++ {
		var temp = individual.NodeMap[i]
		temp.Value = input[i]
	}
}

func (individual *Individual) GetOutput() []float64 {
	var output = make([]float64, individual.OutputNum)
	var pointer = 0
	for i := individual.InputNum; i < len(individual.NodeSlice); i++ {
		var temp = individual.NodeMap[individual.NodeSlice[i]]
		if temp.NodeType == 2 {
			output[pointer] = temp.Value
			pointer++
		}
	}
	return output
}

func (individual *Individual) Forward() {
	for i := individual.InputNum; i < len(individual.NodeSlice); i++ {
		var node = individual.NodeMap[individual.NodeSlice[i]]
		var f float64 = 0
		for gen, ome := range node.GenomeMap {
			if ome.IsEnable {
				f += individual.NodeMap[gen.In].Value * ome.Weight
			}
		}
		node.Value = Func(f)
	}
}
