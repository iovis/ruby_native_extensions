# frozen_string_literal: true

RSpec.describe CDay4 do
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

  context "ruby" do
    subject { described_class.run(input) }

    it { is_expected.to eq 2 }
  end

  context "C" do
    subject { described_class.c_run(input) }

    it { is_expected.to eq 2 }
  end
end
