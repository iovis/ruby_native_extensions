# frozen_string_literal: true

RSpec.describe RsDay4 do
  let(:input) do
    <<~INPUT
      2-4,6-8
      2-3,4-5
      5-7,7-9
      2-8,3-7
      6-6,4-6
      2-6,4-8
    INPUT
  end

  context "single threaded" do
    subject { described_class.run(input) }

    it { is_expected.to eq 2 }
  end

  context "parallel" do
    subject { described_class.run_parallel(input) }

    it { is_expected.to eq 2 }
  end

  context "with_errors" do
    subject { described_class.try_run(input) }

    let(:input) do
      <<~INPUT
        2-4,6-8
        2-3,4-5
        5-7,7-9
        2-8,3-7
        6-6,4-6
        2-6,a-8
      INPUT
    end

    it "reports an error" do
      expect { subject }.to raise_error(
        ArgumentError,
        'Parsing Error: Error { input: "a-8", code: Digit }'
      )
    end
  end
end
